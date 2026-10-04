
undefined4 __thiscall FUN_005f21e1(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  FUN_005d98fc(param_1);
  *(undefined1 *)(param_1 + 0x157) = 1;
  local_c = param_2 - *(int *)(param_1 + 0xfc);
  param_4 = param_4 & 0xffffff01;
  iVar3 = 0;
  local_8 = param_3 - *(int *)(param_1 + 0x100);
  *(undefined4 *)(param_1 + 0x158) = 0xffffffff;
  if (0 < (int)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) & 0xfffffffcU)) {
    do {
      piVar4 = &local_c;
      uVar1 = FUN_004096c2(piVar4);
      iVar2 = FUN_005f22d5(*(undefined4 *)(param_1 + 0x114),uVar1,piVar4);
      if (-1 < iVar2) {
        *(int *)(param_1 + 0x158) = iVar2;
        break;
      }
      if ((iVar2 == -1) &&
         (iVar3 == (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) + -1)) {
        *(int *)(param_1 + 0x158) = (*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2);
  }
  if (-1 < *(int *)(param_1 + 0x158)) {
    FUN_005f2c6c(*(int *)(param_1 + 0x158) - *(int *)(param_1 + 0xd4),param_4,0);
  }
  return 1;
}

