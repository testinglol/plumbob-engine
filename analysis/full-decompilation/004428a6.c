
undefined4 FUN_004428a6(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x34) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(unaff_EBP + -0x34) + 0x30);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(DAT_006e54dc + 0x10);
  *(undefined4 *)(unaff_EBP + -0x18) = 0x40;
  while (*(int *)(unaff_EBP + -0x10) != 0) {
    *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x10) + 0xfc;
    *(undefined1 *)(unaff_EBP + -0x1c) = **(undefined1 **)(unaff_EBP + -0x28);
    *(undefined1 *)(unaff_EBP + -0x1b) = *(undefined1 *)(*(int *)(unaff_EBP + -0x28) + 1);
    *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(*(int *)(unaff_EBP + -0x28) + 2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x118) + 0x14) == 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe0);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 400);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe0);
      while (((*(int *)(unaff_EBP + -0x20) != 0 &&
              (*(short *)(*(int *)(*(int *)(unaff_EBP + -0x20) + 0x118) + 0x14) != 0)) &&
             ((*(int *)(unaff_EBP + -0x24) == *(int *)(unaff_EBP + -0x20) ||
              (*(int *)(unaff_EBP + -0x24) == *(int *)(*(int *)(unaff_EBP + -0x20) + 400)))))) {
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0xe0);
      }
    }
    if ((((*(char *)(unaff_EBP + -0x1c) < '\x01') ||
         (*(int *)(DAT_006e54dc + 0x10) + -1 <= (int)*(char *)(unaff_EBP + -0x1c))) ||
        (*(char *)(unaff_EBP + -0x1b) < '\x01')) ||
       (*(int *)(DAT_006e54dc + 0x10) + -1 <= (int)*(char *)(unaff_EBP + -0x1b))) {
      *(undefined1 *)(unaff_EBP + -0x2c) = 1;
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x2c) = 0;
    }
    if (((*(char *)(unaff_EBP + -0x2c) != '\0') &&
        (*(int *)(unaff_EBP + -0x14) + -1 <= (int)*(char *)(unaff_EBP + -0x1c))) &&
       ((*(int *)(unaff_EBP + -0x14) + -1 <= (int)*(char *)(unaff_EBP + -0x1b) &&
        (((int)*(char *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x18) + -1 &&
         ((int)*(char *)(unaff_EBP + -0x1b) < *(int *)(unaff_EBP + -0x18) + -1)))))) {
      *(undefined2 *)(unaff_EBP + -0x30) = *(undefined2 *)(*(int *)(unaff_EBP + -0x10) + 0xf0);
      FUN_0044127f(*(undefined4 *)(unaff_EBP + -0x30));
    }
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

