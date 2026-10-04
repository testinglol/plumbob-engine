
void FUN_0040957e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_4;
  
  iVar3 = DAT_006e483c;
  if (DAT_006e483c != 0) {
    FUN_004096b4();
    FUN_006321f0(iVar3);
  }
  iVar3 = DAT_006e4838;
  DAT_006e483c = 0;
  if (DAT_006e4838 != 0) {
    FUN_004096b4();
    FUN_006321f0(iVar3);
  }
  DAT_006e4838 = 0;
  iVar3 = DAT_006e4840;
  if (DAT_006e4840 != DAT_006e4844) {
    do {
      piVar4 = (int *)(iVar3 + 0x10);
      iVar2 = 8;
      do {
        iVar1 = *piVar4;
        if (iVar1 != 0) {
          FUN_004096b4();
          FUN_006321f0(iVar1);
        }
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      piVar4 = (int *)(iVar3 + 0x40);
      local_4 = 4;
      do {
        iVar2 = piVar4[-4];
        if (iVar2 != 0) {
          FUN_004096b4();
          FUN_006321f0(iVar2);
        }
        piVar4[-4] = 0;
        iVar2 = *piVar4;
        if (iVar2 != 0) {
          FUN_004096b4();
          FUN_006321f0(iVar2);
        }
        *piVar4 = 0;
        iVar2 = piVar4[4];
        if (iVar2 != 0) {
          FUN_004096b4();
          FUN_006321f0(iVar2);
        }
        piVar4[4] = 0;
        iVar2 = piVar4[8];
        if (iVar2 != 0) {
          FUN_004096b4();
          FUN_006321f0(iVar2);
        }
        piVar4[8] = 0;
        iVar2 = piVar4[0xc];
        if (iVar2 != 0) {
          FUN_004096b4();
          FUN_006321f0(iVar2);
        }
        piVar4[0xc] = 0;
        piVar4 = piVar4 + 1;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
      iVar3 = iVar3 + 0x90;
    } while (iVar3 != DAT_006e4844);
  }
  FUN_0040f641(DAT_006e4840,DAT_006e4844);
  return;
}

