
void __fastcall FUN_0055824d(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  
  FUN_005dae65(param_1);
  if (*(char *)(param_1 + 0x1b0) == '\0') {
    if (*(char *)(param_1 + 0x1d5) != '\0') {
      (**(code **)(*DAT_006fe8bc + 0x18))();
      FUN_005d9dba();
      iVar1 = *(int *)(param_1 + 0x148);
      iVar2 = *(int *)(iVar1 + 8);
      while (iVar2 != iVar1) {
        (**(code **)(**(int **)(iVar2 + 0x14) + 0x160))(0);
        FUN_0041674f();
      }
      *(undefined1 *)(param_1 + 0x1d5) = 0;
      FUN_005584d8();
      cVar3 = FUN_0042c217();
      if (cVar3 != '\0') {
        FUN_0042c141();
        FUN_004f5aa0(1);
      }
      FUN_0042c574();
      FUN_0042c22c(0xc);
      FUN_0042d51d();
      FUN_0042d1d5(0x12);
      FUN_0042d96d();
      FUN_0042d634(0x1e);
      piVar5 = (int *)**(int **)(param_1 + 0x38);
      if (piVar5 != *(int **)(param_1 + 0x38)) {
        do {
          (**(code **)(*(int *)piVar5[2] + 0x90))(0x400,1);
          (**(code **)(*(int *)piVar5[2] + 0x90))(2,1);
          piVar5 = (int *)*piVar5;
        } while (piVar5 != (int *)*(int *)(param_1 + 0x38));
      }
      (**(code **)(**(int **)(param_1 + 0x18c) + 0x90))(0x400,0);
      if ((*(char *)(param_1 + 0x121) != '\0') &&
         (*(short *)(*(int *)(DAT_006e486c + 0x24) + 0x12e) == 0)) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x148) + 8);
        while (iVar2 != iVar1) {
          piVar5 = *(int **)(iVar2 + 0x14);
          if (piVar5[0x6a] == 1) {
            (**(code **)(*piVar5 + 0x160))(1);
          }
          FUN_0041674f();
        }
      }
    }
    iVar1 = *(int *)(param_1 + 0x148);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != iVar1) {
      cVar3 = (**(code **)(**(int **)(iVar2 + 0x14) + 0x8c))(0x400);
      if (cVar3 == '\x01') break;
      (**(code **)(**(int **)(iVar2 + 0x14) + 0x90))(0x400,1);
      FUN_0041674f();
    }
    FUN_0055c517();
    FUN_0042a53a();
    if (*(char *)(param_1 + 0x100) == '\0') {
      uVar4 = FUN_0046f556();
      if ((int)((ulonglong)uVar4 % 1000) == 1) {
        *(undefined4 *)(param_1 + 0x10c) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x114) = 0xffffffff;
        *(char *)(param_1 + 0x100) = (char)((ulonglong)uVar4 % 1000);
        *(undefined4 *)(param_1 + 0x104) = 0x76;
        *(undefined4 *)(param_1 + 0x108) = 0x207;
      }
    }
    FUN_005dadff(param_1,1000,0);
  }
  else {
    FUN_0055cb93();
    FUN_005dadbc(0,1);
  }
  return;
}

