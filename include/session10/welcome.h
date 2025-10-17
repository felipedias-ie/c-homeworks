#pragma once

/**
 * @brief Returns the welcome message based on the LANGUAGE macro defined at compile time.
 * @return A constant string containing the welcome message in the selected language.
 * @note The LANGUAGE macro should be defined as EN for English or ES for Spanish.
 *       If LANGUAGE is not defined, a default language will be used.
 */
const char *get_welcome_msg(void);

