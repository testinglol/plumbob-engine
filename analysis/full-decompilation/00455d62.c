
void __thiscall FUN_00455d62(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined **local_110 [3];
  undefined1 local_104 [256];
  
  iVar1 = param_2;
  if (0x2d < param_3) {
    param_2 = CONCAT13(DAT_006c42bc != 0,(undefined3)param_2);
    FUN_0046494e((int)&param_2 + 3);
    if (param_2._3_1_ != '\0') {
      FUN_004645e3();
    }
  }
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    if (*(int *)(iVar1 + 0xc) == 0) {
      iVar2 = FUN_0043acf5(0x3c08965f);
      if (param_1[3] == iVar2) {
        *(undefined1 *)(param_1 + 4) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 4) = 0;
      }
    }
    FUN_0043bfaf(param_1 + 3,0,iVar1,0,param_3);
    if ((0x26 < param_3) && (param_3 < 0x2f)) {
      FUN_0046f824(local_104,0,0x100);
      local_110[0] = &PTR_FUN_00666524;
      FUN_00464d2c(local_110);
    }
    (**(code **)(*(int *)*param_1 + 0x7c))(iVar1,param_3,*(undefined1 *)(param_1 + 4));
    if (*(char *)(param_1 + 4) != '\0') {
      (**(code **)(*(int *)*param_1 + 0x40))(0);
    }
  }
  else {
    FUN_00455bb9(iVar1,param_3);
  }
  return;
}

