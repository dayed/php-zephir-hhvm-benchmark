
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "benchmark.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *benchmark_benchmark_ce;

ZEND_DECLARE_MODULE_GLOBALS(benchmark)

static PHP_MINIT_FUNCTION(benchmark)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Benchmark_Benchmark);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(benchmark)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_benchmark_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(benchmark)
{

	zend_benchmark_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(benchmark)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(benchmark)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_BENCHMARK_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_BENCHMARK_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_BENCHMARK_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_BENCHMARK_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_BENCHMARK_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(benchmark)
{
	php_zephir_init_globals(benchmark_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(benchmark)
{

}

zend_module_entry benchmark_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_BENCHMARK_EXTNAME,
	NULL,
	PHP_MINIT(benchmark),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(benchmark),
#else
	NULL,
#endif
	PHP_RINIT(benchmark),
	PHP_RSHUTDOWN(benchmark),
	PHP_MINFO(benchmark),
	PHP_BENCHMARK_VERSION,
	ZEND_MODULE_GLOBALS(benchmark),
	PHP_GINIT(benchmark),
	PHP_GSHUTDOWN(benchmark),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BENCHMARK
ZEND_GET_MODULE(benchmark)
#endif
