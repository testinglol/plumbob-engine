
undefined4 __fastcall FUN_00577c42(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_c;
  int *local_8;
  
  if (((char)param_1[1] != '\0') && ((char)param_1[0xf] != '\0')) {
    (**(code **)(*param_1 + 0x6c))();
    FUN_005772fa(param_1);
    if (param_1[0xc] != 0) {
      FUN_005771b0();
      if (param_1[0xc] != 0) {
        FUN_006321f0(param_1[0xc]);
      }
      param_1[0xc] = 0;
    }
    iVar1 = param_1[0xd];
    local_c = 0;
    if (0 < *(int *)(iVar1 + 0x24)) {
      local_8 = param_1 + 0x25;
      do {
        iVar2 = 0;
        piVar3 = local_8;
        if (0 < *(int *)(iVar1 + 0x28)) {
          do {
            if (*(int *)(*piVar3 + 8) != 0) {
              FUN_00579e40();
            }
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 1;
          } while (iVar2 < *(int *)(param_1[0xd] + 0x28));
        }
        local_c = local_c + 1;
        iVar1 = param_1[0xd];
        local_8 = local_8 + 0x40;
      } while (local_c < *(int *)(iVar1 + 0x24));
    }
    *(undefined1 *)(param_1 + 0xf) = 0;
  }
  return 1;
}

