<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/documentation/article/editing-wp-config-php/
 *
 * @package WordPress
 */

/** Database charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The database collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'u/s$l/]P]U^5Z >-@K(Y[g/:)-`W#z!8@HPHqk8yV6K[IzueJ{T_!k|I%}x FI1S');
define('SECURE_AUTH_KEY',  '/p>]-qE#OwffUW}]S)1@8<]oiS&stTGQU5(tFskZVDN<31Hc}|Exqe.0<O &Q+j]');
define('LOGGED_IN_KEY',    '5Z:jq0XfXD*|KX];(s-4!%<Md|Gu_#zO|3Svd_gj wpY}*DNwQ <=V- j8>i4/II');
define('NONCE_KEY',        'hp:X9E$,WXf`%GLJ!E4Nm2J5!cS3{:ZMGzcQQ{K:2Kp7XdsT7>36]jeuT%K/y&Ds');
define('AUTH_SALT',        'r{4[:l!ZC#|tY0SSxzPp7Ky:-q`MnH.PK6Sj.651Fm6blT]50U[ulzq--]cjG=+X');
define('SECURE_AUTH_SALT', '9OpN>>k<L`-XZ5AIX*9MHlDECs]m-Yez N0f8!`8Cu-wmWGT3hoP^x24+;]E8:aS');
define('LOGGED_IN_SALT',   '/.y2$}D2C8os7,gsgojzwV2v%FN %Ail{o3&@Rn(D+Ng+nkhtF)86NXE`3y?UBS[');
define('NONCE_SALT',       '6tv}`C,idfzCPSZu+WXfzrsSv_|`!-?jO2I+Q]Gk.6Y1n26pP4SlN|lax*$plgt-');
/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/documentation/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
/** Sets up WordPress vars and included files. */