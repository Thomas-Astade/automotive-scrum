//~~ void create(const std::string& outpath) [File_creator] ~~
FILE *write_ptr;

write_ptr = fopen("folder.png","wb");
fwrite(Folder_small_png,sizeof(Folder_small_png),1,write_ptr);
fclose(write_ptr);
