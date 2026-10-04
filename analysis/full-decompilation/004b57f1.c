
void __fastcall FUN_004b57f1(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  local_c = param_1[1] - *param_1 >> 2;
  if (0 < local_c) {
    iVar3 = 0;
    do {
      if (*(int *)(iVar3 + *param_1) != 0) {
        FUN_0049c027();
        if (*(int *)(iVar3 + *param_1) != 0) {
          FUN_006321f0(*(int *)(iVar3 + *param_1));
        }
      }
      piVar2 = param_1 + 0xc;
      local_8 = 3;
      do {
        if (*(int *)(piVar2[-9] + iVar3) != 0) {
          FUN_004bb6c5();
          iVar1 = *(int *)(iVar3 + piVar2[-9]);
          if (iVar1 != 0) {
            FUN_0042004f();
            FUN_006321f0(iVar1);
          }
        }
        if (*(int *)(*piVar2 + iVar3) != 0) {
          FUN_004bb6c5();
          iVar1 = *(int *)(iVar3 + *piVar2);
          if (iVar1 != 0) {
            FUN_0042004f();
            FUN_006321f0(iVar1);
          }
        }
        piVar2 = piVar2 + 3;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      iVar3 = iVar3 + 4;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  FUN_004b6005(*param_1,param_1[1]);
  iVar3 = 3;
  piVar2 = param_1;
  do {
    FUN_0052ea87(piVar2[3],piVar2[4]);
    FUN_0052ea87(piVar2[0xc],piVar2[0xd]);
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 3;
  } while (iVar3 != 0);
  piVar2 = param_1 + 0x15;
  iVar3 = 3;
  do {
    if (*piVar2 != 0) {
      FUN_004a3a06();
      if (*piVar2 != 0) {
        FUN_006321f0(*piVar2);
      }
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = param_1[0x18];
  if (iVar3 != 0) {
    FUN_005b8e25(iVar3);
    FUN_005b95c0(iVar3);
    param_1[0x18] = 0;
  }
  return;
}

