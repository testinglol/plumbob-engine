
undefined4 __thiscall FUN_005f2553(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_c;
  int local_8;
  
  local_c = param_2;
  if (*(char *)(param_1 + 0x157) != '\0') {
    param_2 = 0;
    local_c = local_c - *(int *)(param_1 + 0xfc);
    local_8 = param_3 - *(int *)(param_1 + 0x100);
    iVar2 = -1;
    if (0 < (int)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) & 0xfffffffcU)) {
      do {
        piVar3 = &local_c;
        uVar1 = FUN_004096c2(piVar3);
        iVar2 = FUN_005f22d5(*(undefined4 *)(param_1 + 0x114),uVar1,piVar3);
        if (-1 < iVar2) break;
        if ((iVar2 == -1) &&
           (param_2 == (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) + -1)) {
          iVar2 = (*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1;
          break;
        }
        if ((iVar2 == -3) && (param_2 == 0)) {
          iVar2 = 0;
          break;
        }
        param_2 = param_2 + 1;
        iVar2 = -1;
      } while (param_2 < *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2);
    }
    FUN_005f2c6c(iVar2 - *(int *)(param_1 + 0xd4),1,0);
  }
  return 1;
}

