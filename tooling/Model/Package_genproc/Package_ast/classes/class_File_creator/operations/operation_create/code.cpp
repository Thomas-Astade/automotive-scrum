//~~ void create(const std::string& outpath) [File_creator] ~~
FILE *write_ptr;

write_ptr = fopen("folder.png","wb");
fwrite(Folder_small_png,sizeof(Folder_small_png),1,write_ptr);
fclose(write_ptr);

write_ptr = fopen("folder_selected.png","wb");
fwrite(Folder_selected_small_png,sizeof(Folder_selected_small_png),1,write_ptr);
fclose(write_ptr);

write_ptr = fopen("repository.png","wb");
fwrite(repository_small_png,sizeof(repository_small_png),1,write_ptr);
fclose(write_ptr);

write_ptr = fopen("repository_selected.png","wb");
fwrite(repository_selected_small_png,sizeof(repository_selected_small_png),1,write_ptr);
fclose(write_ptr);

write_ptr = fopen("role.png","wb");
fwrite(actor_klein_png,sizeof(actor_klein_png),1,write_ptr);
fclose(write_ptr);

write_ptr = fopen("tool.png","wb");
fwrite(tools_small_png,sizeof(tools_small_png),1,write_ptr);
fclose(write_ptr);
