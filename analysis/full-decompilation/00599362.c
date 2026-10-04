
void __thiscall FUN_00599362(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  if ((param_2 != '\0') || (*(int *)(param_1 + 0x98) != 0)) {
    FUN_0059940d();
    FUN_00599556();
    _param_2 = 0;
    iVar4 = *(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x88) >> 2;
    if (0 < iVar4) {
      do {
        iVar1 = *(int *)(*(int *)(param_1 + 0x88) + _param_2 * 4);
        if ((iVar1 != 0) &&
           (local_c = (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8)) / 0xc, 0 < local_c)) {
          local_8 = 0;
          do {
            piVar3 = (int *)(*(int *)(iVar1 + 8) + local_8);
            if (((*piVar3 != 0) && (iVar2 = piVar3[2], iVar2 != 0)) && (*(int *)(iVar2 + 8) != 0)) {
              FUN_0059a1ce(iVar2,0);
            }
            local_8 = local_8 + 0xc;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        _param_2 = _param_2 + 1;
      } while (_param_2 < iVar4);
    }
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  return;
}

