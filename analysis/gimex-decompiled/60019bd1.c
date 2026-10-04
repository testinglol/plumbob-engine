
int FUN_60019bd1(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar1 = FUN_60019b4a(param_2);
  if (iVar1 == 0x5a) {
    iVar1 = FUN_60019d6f(param_1,param_2);
  }
  else {
    puVar2 = (undefined4 *)FUN_600021ef(0x18);
    piVar3 = (int *)FUN_600021ef(0x10);
    uVar4 = FUN_600021cd(param_2);
    iVar1 = FUN_600021ef(uVar4);
    if (((puVar2 != (undefined4 *)0x0) && (piVar3 != (int *)0x0)) && (iVar1 != 0)) {
      FUN_600021b8(param_2,0);
      uVar4 = FUN_600021cd(param_2);
      iVar5 = FUN_60002186(param_2,iVar1,uVar4);
      if (iVar5 != 0) {
        *piVar3 = 0;
        piVar3[1] = 0;
        piVar3[2] = 0;
        piVar3[3] = 0;
        *piVar3 = iVar1;
        iVar5 = FUN_600011b3((byte *)(iVar1 + 0x14),4);
        piVar3[1] = iVar1 + iVar5;
        iVar5 = FUN_600011b3((byte *)(iVar1 + 0x1c),4);
        piVar3[2] = iVar1 + iVar5;
        iVar1 = FUN_6001a28a((undefined1 *)piVar3[2]);
        piVar3[3] = iVar1;
        puVar6 = puVar2;
        for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        *puVar2 = 0x464e5446;
        puVar2[1] = 0x18;
        iVar1 = FUN_600011b3((byte *)(*piVar3 + 10),2);
        puVar2[2] = iVar1;
        puVar2[4] = param_2;
        puVar2[5] = piVar3;
        *param_1 = puVar2;
        return puVar2[2];
      }
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_60002200(puVar2);
    }
    if (piVar3 != (int *)0x0) {
      FUN_60002200(piVar3);
    }
    if (iVar1 != 0) {
      FUN_60002200(iVar1);
    }
    *param_1 = 0;
    iVar1 = 0;
  }
  return iVar1;
}

