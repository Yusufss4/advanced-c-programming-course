int main()
{
    char *str = "Yusuf Engineer 21";
    char name[20], title[20];
    int age = 0, ret = 0;

    ret = sscanf(str, "%s %s %d", name, title, &age);
    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);

    return ret;
}