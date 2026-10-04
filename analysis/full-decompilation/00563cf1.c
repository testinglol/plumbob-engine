
void __fastcall FUN_00563cf1(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x42] = 0;
    param_1[0x43] = 0;
    param_1[0x44] = 0;
    param_1[0x45] = 0;
    param_1[0x4c] = 0;
    if ((undefined4 *)param_1[0x50] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x50])(1);
    }
    param_1[0x50] = 0;
    if ((undefined4 *)param_1[0x4f] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4f])(1);
    }
    param_1[0x4f] = 0;
    *(int *)(DAT_006fe8f4 + 0x1fc) = param_1[0x53];
  }
  FUN_005e8e14();
  return;
}

