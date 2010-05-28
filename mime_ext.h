#ifndef MIME_EXT_H
#define MIME_EXT_H

#define MIME_EXTS 202

const char *mime_ext[][2] = {
  {"stl","application/SLA"},
  {"step","application/STEP"},
  {"stp","application/STEP"},
  {"dwg","application/acad"},
  {"ez","application/andrew-inset"},
  {"ccad","application/clariscad"},
  {"drw","application/drafting"},
  {"tsp","application/dsptype"},
  {"dxf","application/dxf"},
  {"xls","application/excel"},
  {"unv","application/i-deas"},
  {"jar","application/java-archive"},
  {"hqx","application/mac-binhex40"},
  {"cpt","application/mac-compactpro"},
  {"pot","application/vnd.ms-powerpoint"},
  {"pps","application/vnd.ms-powerpoint"},
  {"ppt","application/vnd.ms-powerpoint"},
  {"ppz","application/vnd.ms-powerpoint"},
  {"doc","application/msword"},
  {"bin","application/octet-stream"},
  {"class","application/octet-stream"},
  {"dms","application/octet-stream"},
  {"exe","application/octet-stream"},
  {"lha","application/octet-stream"},
  {"lzh","application/octet-stream"},
  {"oda","application/oda"},
  {"ogg","application/ogg"},
  {"ogm","application/ogg"},
  {"pdf","application/pdf"},
  {"pgp","application/pgp"},
  {"ai","application/postscript"},
  {"eps","application/postscript"},
  {"ps","application/postscript"},
  {"prt","application/pro_eng"},
  {"rtf","application/rtf"},
  {"set","application/set"},
  {"smi","application/smil"},
  {"smil","application/smil"},
  {"sol","application/solids"},
  {"vda","application/vda"},
  {"mif","application/vnd.mif"},
  {"xlc","application/vnd.ms-excel"},
  {"xll","application/vnd.ms-excel"},
  {"xlm","application/vnd.ms-excel"},
  {"xls","application/vnd.ms-excel"},
  {"xlw","application/vnd.ms-excel"},
  {"cod","application/vnd.rim.cod"},
  {"arj","application/x-arj-compressed"},
  {"bcpio","application/x-bcpio"},
  {"vcd","application/x-cdlink"},
  {"pgn","application/x-chess-pgn"},
  {"cpio","application/x-cpio"},
  {"csh","application/x-csh"},
  {"deb","application/x-debian-package"},
  {"dcr","application/x-director"},
  {"dir","application/x-director"},
  {"dxr","application/x-director"},
  {"dvi","application/x-dvi"},
  {"pre","application/x-freelance"},
  {"spl","application/x-futuresplash"},
  {"gtar","application/x-gtar"},
  {"gz","application/x-gunzip"},
  {"gz","application/x-gzip"},
  {"hdf","application/x-hdf"},
  {"ipx","application/x-ipix"},
  {"ips","application/x-ipscript"},
  {"js","application/x-javascript"},
  {"skd","application/x-koan"},
  {"skm","application/x-koan"},
  {"skp","application/x-koan"},
  {"skt","application/x-koan"},
  {"latex","application/x-latex"},
  {"lsp","application/x-lisp"},
  {"scm","application/x-lotusscreencam"},
  {"mif","application/x-mif"},
  {"bat","application/x-msdos-program"},
  {"com","application/x-msdos-program"},
  {"exe","application/x-msdos-program"},
  {"cdf","application/x-netcdf"},
  {"nc","application/x-netcdf"},
  {"pl","application/x-perl"},
  {"pm","application/x-perl"},
  {"rar","application/x-rar-compressed"},
  {"sh","application/x-sh"},
  {"shar","application/x-shar"},
  {"swf","application/x-shockwave-flash"},
  {"sit","application/x-stuffit"},
  {"sv4cpio","application/x-sv4cpio"},
  {"sv4crc","application/x-sv4crc"},
  {"tar.gz","application/x-tar-gz"},
  {"tgz","application/x-tar-gz"},
  {"tar","application/x-tar"},
  {"tcl","application/x-tcl"},
  {"tex","application/x-tex"},
  {"texi","application/x-texinfo"},
  {"texinfo","application/x-texinfo"},
  {"man","application/x-troff-man"},
  {"me","application/x-troff-me"},
  {"ms","application/x-tross-ms"},
  {"roff","application/x-troff"},
  {"t","application/x-troff"},
  {"tr","application/x-troff"},
  {"ustar","application/x-ustar"},
  {"src","application/x-wais-source"},
  {"zip","application/x-zip-compressed"},
  {"zip","application/zip"},
  {"tsi","audio/TSP-audio"},
  {"au","audio/basic"},
  {"snd","audio/basic"},
  {"kar","audio/midi"},
  {"mid","audio/midi"},
  {"midi","audio/midi"},
  {"mp2","audio/mpeg"},
  {"mp3","audio/mpeg"},
  {"mpga","audio/mpeg"},
  {"au","audio/ulaw"},
  {"aif","audio/x-aiff"},
  {"aifc","audio/x-aiff"},
  {"aiff","audio/x-aiff"},
  {"m3u","audio/x-mpegurl"},
  {"wax","audio/x-ms-wax"},
  {"wma","audio/x-ms-wma"},
  {"rpm","audio/x-pn-realaudio-plugin"},
  {"ram","audio/x-pn-realaudio"},
  {"rm","audio/x-pn-realaudio"},
  {"ra","audio/x-realaudio"},
  {"wav","audio/x-wav"},
  {"pdb","chemical/x-pdb"},
  {"xyz","chemical/x-pdb"},
  {"ras","image/cmu-raster"},
  {"gif","image/gif"},
  {"ief","image/ief"},
  {"jpe","image/jpeg"},
  {"jpeg","image/jpeg"},
  {"jpg","image/jpeg"},
  {"png","image/png"},
  {"tif tiff","image/tiff"},
  {"tif","image/tiff"},
  {"tiff","image/tiff"},
  {"ras","image/x-cmu-raster"},
  {"pnm","image/x-portable-anymap"},
  {"pbm","image/x-portable-bitmap"},
  {"pgm","image/x-portable-graymap"},
  {"ppm","image/x-portable-pixmap"},
  {"rgb","image/x-rgb"},
  {"xbm","image/x-xbitmap"},
  {"xpm","image/x-xpixmap"},
  {"xwd","image/x-xwindowdump"},
  {"iges","model/iges"},
  {"igs","model/iges"},
  {"mesh","model/mesh"},
  {"msh","model/mesh"},
  {"silo","model/mesh"},
  {"vrml","model/vrml"},
  {"wrl","model/vrml"},
  {"css","text/css"},
  {"htm","text/html"},
  {"html htm","text/html"},
  {"html","text/html"},
  {"asc txt","text/plain"},
  {"asc","text/plain"},
  {"c","text/plain"},
  {"cc","text/plain"},
  {"f90","text/plain"},
  {"f","text/plain"},
  {"h","text/plain"},
  {"hh","text/plain"},
  {"m","text/plain"},
  {"txt","text/plain"},
  {"rtx","text/richtext"},
  {"rtf","text/rtf"},
  {"sgm","text/sgml"},
  {"sgml","text/sgml"},
  {"tsv","text/tab-separated-values"},
  {"jad","text/vnd.sun.j2me.app-descriptor"},
  {"etx","text/x-setext"},
  {"xml","text/xml"},
  {"dl","video/dl"},
  {"fli","video/fli"},
  {"flv","video/flv"},
  {"gl","video/gl"},
  {"mp2","video/mpeg"},
  {"mp4","video/mp4"},
  {"mpe","video/mpeg"},
  {"mpeg","video/mpeg"},
  {"mpg","video/mpeg"},
  {"mov","video/quicktime"},
  {"qt","video/quicktime"},
  {"viv","video/vnd.vivo"},
  {"vivo","video/vnd.vivo"},
  {"fli","video/x-fli"},
  {"asf","video/x-ms-asf"},
  {"asx","video/x-ms-asx"},
  {"wmv","video/x-ms-wmv"},
  {"wmx","video/x-ms-wmx"},
  {"wvx","video/x-ms-wvx"},
  {"avi","video/x-msvideo"},
  {"movie","video/x-sgi-movie"},
  {"mime","www/mime"},
  {"ice","x-conference/x-cooltalk"},
  {"vrm","x-world/x-vrml"},
  {"vrml","x-world/x-vrml"}
};

#endif
