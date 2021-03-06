%define name libofx
%define version 0.9.4
%define release 1
%define prefix /usr

Summary: The LibOFX library is designed to allow applications to very easily support OFX command responses
Name: %{name}
Version: %{version}
Release: %{release}
Source: http://download.sourceforge.net/libofx/%{name}-%{version}.tar.gz
Requires: openjade >= 1.3.1
Group:	Libraries/System
License:  GPL
Packager: Chris Lyttle <chris@wilddev.net>
BuildRoot: %{_tmppath}/%{name}-%{version}-root
Prereq: /sbin/ldconfig

%description
This is the LibOFX library.  It is a API designed to allow applications to
very easily support OFX command responses, usually provided by financial
institutions.  See http://www.ofx.net/ofx/default.asp for details and
specification. LibOFX is based on the excellent OpenSP library written by
James Clark, and now part of the OpenJADE http://openjade.sourceforge.net/
project.  OpenSP by itself is not widely distributed.  OpenJADE 1.3.1 includes
a version on OpenSP that will link, however, it has some major problems with
LibOFX and isn't recommended.  Since LibOFX uses the generic interface to
OpenSP, it should be compatible with all recent versions of OpenSP (It has
been developed with OpenSP-1.5pre5).  LibOFX is written in C++, but provides a
C style interface usable transparently from both C and C++ using a single
include file.

%prep
%setup -q

%build
./configure --prefix=%{_prefix} \
            --libdir=%{_libdir} --datadir=%{_datadir} \
            --includedir=%{_includedir}

make RPM_OPT_FLAGS="$RPM_OPT_FLAGS"

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT%{prefix}

LIBRARY_PATH=$RPM_BUILD_ROOT%{_libdir} make prefix=$RPM_BUILD_ROOT%{_prefix} \
    libdir=$RPM_BUILD_ROOT%{_libdir} \
    datadir=$RPM_BUILD_ROOT%{_datadir} \
    includedir=$RPM_BUILD_ROOT%{_includedir} install

%makeinstall

%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root)
%doc AUTHORS COPYING ChangeLog INSTALL NEWS README
%{_bindir}/*
%{_libdir}/*.a
%{_libdir}/*.la
%{_libdir}/*.so*
%{_libdir}/pkgconfig/libofx.pc
%{_includedir}/*
%{_datadir}/%{name}/dtd/*
%{_datadir}/doc/%{name}

%changelog
* Sat Nov 23 2002 Chris Lyttle <chris@wilddev.net>
- Created spec file
