/*
  File autogenerated by gengetopt version 2.21
  generated with the following command:
  gengetopt --unamed-opts 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "ofxdump prints to stdout, in human readable form, everything the library \n understands about a particular file or response, and sends errors to \n stderr.  To know exactly what the library understands about of a particular\n ofx response file, just call ofxdump on that file.";

const char *gengetopt_args_info_usage = "Usage: " CMDLINE_PARSER_PACKAGE " [OPTIONS]... [FILES]...";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                  Print help and exit",
  "  -V, --version               Print version and exit",
  "  -f, --import-format=STRING  Force the file format of the file(s) specified  \n                                (default=`AUTODETECT')",
  "      --list-import-formats   List available import file formats \n                                'import-format' command",
  "      --msg_parser            Output file parsing messages  (default=off)",
  "      --msg_debug             Output messages meant for debuging  (default=off)",
  "      --msg_warning           Output warning messages about abnormal conditions \n                                and unknown constructs  (default=on)",
  "      --msg_error             Output error messages  (default=on)",
  "      --msg_info              Output informational messages about the progress \n                                of the library  (default=on)",
  "      --msg_status            Output status messages  (default=on)",
    0
};

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->import_format_given = 0 ;
  args_info->list_import_formats_given = 0 ;
  args_info->msg_parser_given = 0 ;
  args_info->msg_debug_given = 0 ;
  args_info->msg_warning_given = 0 ;
  args_info->msg_error_given = 0 ;
  args_info->msg_info_given = 0 ;
  args_info->msg_status_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->import_format_arg = gengetopt_strdup ("AUTODETECT");
  args_info->import_format_orig = NULL;
  args_info->msg_parser_flag = 0;
  args_info->msg_debug_flag = 0;
  args_info->msg_warning_flag = 1;
  args_info->msg_error_flag = 1;
  args_info->msg_info_flag = 1;
  args_info->msg_status_flag = 1;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{
  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->import_format_help = gengetopt_args_info_help[2] ;
  args_info->list_import_formats_help = gengetopt_args_info_help[3] ;
  args_info->msg_parser_help = gengetopt_args_info_help[4] ;
  args_info->msg_debug_help = gengetopt_args_info_help[5] ;
  args_info->msg_warning_help = gengetopt_args_info_help[6] ;
  args_info->msg_error_help = gengetopt_args_info_help[7] ;
  args_info->msg_info_help = gengetopt_args_info_help[8] ;
  args_info->msg_status_help = gengetopt_args_info_help[9] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  printf("\n%s\n\n", gengetopt_args_info_usage);

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n", gengetopt_args_info_description);

  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = NULL;
  args_info->inputs_num = 0;
}

struct cmdline_parser_params *
cmdline_parser_params_init()
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));

  if (params)
    { 
      params->override = 0;
      params->initialize = 0;
      params->check_required = 0;
      params->check_ambiguity = 0;
    }
    
  return params;
}

static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  
  unsigned int i;
  if (args_info->import_format_arg)
    {
      free (args_info->import_format_arg); /* free previous argument */
      args_info->import_format_arg = 0;
    }
  if (args_info->import_format_orig)
    {
      free (args_info->import_format_orig); /* free previous argument */
      args_info->import_format_orig = 0;
    }
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);
  
  if (args_info->inputs_num)
    free (args_info->inputs);
  
  clear_given (args_info);
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  if (args_info->help_given) {
    fprintf(outfile, "%s\n", "help");
  }
  if (args_info->version_given) {
    fprintf(outfile, "%s\n", "version");
  }
  if (args_info->import_format_given) {
    if (args_info->import_format_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "import-format", args_info->import_format_orig);
    } else {
      fprintf(outfile, "%s\n", "import-format");
    }
  }
  if (args_info->list_import_formats_given) {
    fprintf(outfile, "%s\n", "list-import-formats");
  }
  if (args_info->msg_parser_given) {
    fprintf(outfile, "%s\n", "msg_parser");
  }
  if (args_info->msg_debug_given) {
    fprintf(outfile, "%s\n", "msg_debug");
  }
  if (args_info->msg_warning_given) {
    fprintf(outfile, "%s\n", "msg_warning");
  }
  if (args_info->msg_error_given) {
    fprintf(outfile, "%s\n", "msg_error");
  }
  if (args_info->msg_info_given) {
    fprintf(outfile, "%s\n", "msg_info");
  }
  if (args_info->msg_status_given) {
    fprintf(outfile, "%s\n", "msg_status");
  }
  
  fclose (outfile);

  i = EXIT_SUCCESS;
  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}


/* gengetopt_strdup() */
/* strdup.c replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;

  result = cmdline_parser_internal (argc, argv, args_info, &params, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  return EXIT_SUCCESS;
}

int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      char *stop_char;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "import-format",	1, NULL, 'f' },
        { "list-import-formats",	0, NULL, 0 },
        { "msg_parser",	0, NULL, 0 },
        { "msg_debug",	0, NULL, 0 },
        { "msg_warning",	0, NULL, 0 },
        { "msg_error",	0, NULL, 0 },
        { "msg_info",	0, NULL, 0 },
        { "msg_status",	0, NULL, 0 },
        { NULL,	0, NULL, 0 }
      };

      stop_char = 0;
      c = getopt_long (argc, argv, "hVf:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'f':	/* Force the file format of the file(s) specified.  */
          if (local_args_info.import_format_given || (check_ambiguity && args_info->import_format_given))
            {
              fprintf (stderr, "%s: `--import-format' (`-f') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->import_format_given && ! override)
            continue;
          local_args_info.import_format_given = 1;
          args_info->import_format_given = 1;
          if (args_info->import_format_arg)
            free (args_info->import_format_arg); /* free previous string */
          args_info->import_format_arg = gengetopt_strdup (optarg);
          if (args_info->import_format_orig)
            free (args_info->import_format_orig); /* free previous string */
          args_info->import_format_orig = gengetopt_strdup (optarg);
          break;


        case 0:	/* Long option with no short option */
          /* List available import file formats 'import-format' command.  */
          if (strcmp (long_options[option_index].name, "list-import-formats") == 0)
          {
            if (local_args_info.list_import_formats_given || (check_ambiguity && args_info->list_import_formats_given))
              {
                fprintf (stderr, "%s: `--list-import-formats' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->list_import_formats_given && ! override)
              continue;
            local_args_info.list_import_formats_given = 1;
            args_info->list_import_formats_given = 1;
            break;
          }
          /* Output file parsing messages.  */
          else if (strcmp (long_options[option_index].name, "msg_parser") == 0)
          {
            if (local_args_info.msg_parser_given || (check_ambiguity && args_info->msg_parser_given))
              {
                fprintf (stderr, "%s: `--msg_parser' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->msg_parser_given && ! override)
              continue;
            local_args_info.msg_parser_given = 1;
            args_info->msg_parser_given = 1;
            args_info->msg_parser_flag = !(args_info->msg_parser_flag);
          }
          /* Output messages meant for debuging.  */
          else if (strcmp (long_options[option_index].name, "msg_debug") == 0)
          {
            if (local_args_info.msg_debug_given || (check_ambiguity && args_info->msg_debug_given))
              {
                fprintf (stderr, "%s: `--msg_debug' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->msg_debug_given && ! override)
              continue;
            local_args_info.msg_debug_given = 1;
            args_info->msg_debug_given = 1;
            args_info->msg_debug_flag = !(args_info->msg_debug_flag);
          }
          /* Output warning messages about abnormal conditions and unknown constructs.  */
          else if (strcmp (long_options[option_index].name, "msg_warning") == 0)
          {
            if (local_args_info.msg_warning_given || (check_ambiguity && args_info->msg_warning_given))
              {
                fprintf (stderr, "%s: `--msg_warning' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->msg_warning_given && ! override)
              continue;
            local_args_info.msg_warning_given = 1;
            args_info->msg_warning_given = 1;
            args_info->msg_warning_flag = !(args_info->msg_warning_flag);
          }
          /* Output error messages.  */
          else if (strcmp (long_options[option_index].name, "msg_error") == 0)
          {
            if (local_args_info.msg_error_given || (check_ambiguity && args_info->msg_error_given))
              {
                fprintf (stderr, "%s: `--msg_error' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->msg_error_given && ! override)
              continue;
            local_args_info.msg_error_given = 1;
            args_info->msg_error_given = 1;
            args_info->msg_error_flag = !(args_info->msg_error_flag);
          }
          /* Output informational messages about the progress of the library.  */
          else if (strcmp (long_options[option_index].name, "msg_info") == 0)
          {
            if (local_args_info.msg_info_given || (check_ambiguity && args_info->msg_info_given))
              {
                fprintf (stderr, "%s: `--msg_info' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->msg_info_given && ! override)
              continue;
            local_args_info.msg_info_given = 1;
            args_info->msg_info_given = 1;
            args_info->msg_info_flag = !(args_info->msg_info_flag);
          }
          /* Output status messages.  */
          else if (strcmp (long_options[option_index].name, "msg_status") == 0)
          {
            if (local_args_info.msg_status_given || (check_ambiguity && args_info->msg_status_given))
              {
                fprintf (stderr, "%s: `--msg_status' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->msg_status_given && ! override)
              continue;
            local_args_info.msg_status_given = 1;
            args_info->msg_status_given = 1;
            args_info->msg_status_flag = !(args_info->msg_status_flag);
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
