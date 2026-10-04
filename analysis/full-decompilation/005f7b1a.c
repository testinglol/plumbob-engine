
undefined4 __thiscall FUN_005f7b1a(int param_1,undefined1 *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x4a48) < 1) {
    if (3 < param_3) {
      *(undefined1 **)(param_1 + 0x4a44) = param_2;
      iVar2 = FUN_0062bceb(CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]));
      if (-1 < iVar2) {
        *(int *)(param_1 + 0x4a48) = param_3;
        *(undefined4 *)(param_1 + 0x4a4c) = param_4;
        return 0;
      }
    }
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

