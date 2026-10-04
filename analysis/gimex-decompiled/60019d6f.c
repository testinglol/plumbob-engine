
int __cdecl FUN_60019d6f(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 uStack0000000c;
  int local_8;
  
  local_8 = 0;
  piVar1 = (int *)FUN_600021ef(0x20);
  uStack0000000c = 0;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)FUN_600021ef(0x20);
    piVar8 = piVar1;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
    }
    if (puVar2 == (undefined4 *)0x0) {
      FUN_60002200(piVar1);
    }
    else {
      puVar3 = (undefined4 *)FUN_600021ef(0x18);
      puVar9 = puVar2;
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      if (puVar3 != (undefined4 *)0x0) {
        puVar9 = puVar3;
        for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        FUN_600021b8(param_2,0);
        FUN_60002186(param_2,puVar2,0x20);
        iVar4 = FUN_60019f9c((int)puVar2);
        FUN_60002200(puVar2);
        iVar5 = FUN_600021ef(iVar4 * 4 + 0x20);
        FUN_600021b8(param_2,0);
        FUN_60002186(param_2,iVar5,iVar4 * 4 + 0x20);
        *piVar1 = iVar5;
        iVar7 = iVar4;
        iVar6 = FUN_600011b3((byte *)(iVar5 + 0x12),2);
        FUN_6001a02a(param_2,piVar1 + 1,iVar6,iVar7);
        iVar7 = iVar4;
        iVar6 = FUN_600011b3((byte *)(iVar5 + 0x14),2);
        FUN_6001a02a(param_2,piVar1 + 2,iVar6,iVar7);
        iVar7 = iVar4;
        iVar6 = FUN_600011b3((byte *)(iVar5 + 0x16),2);
        FUN_6001a02a(param_2,piVar1 + 3,iVar6,iVar7);
        iVar7 = iVar4;
        iVar6 = FUN_600011b3((byte *)(iVar5 + 0x18),2);
        FUN_6001a02a(param_2,piVar1 + 4,iVar6,iVar7);
        iVar7 = iVar4;
        iVar5 = FUN_600011b3((byte *)(iVar5 + 0x1a),2);
        FUN_6001a02a(param_2,piVar1 + 5,iVar5,iVar7);
        FUN_6001a095(param_2,piVar1);
        puVar2 = puVar3;
        for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        puVar3[2] = iVar4;
        *puVar3 = 0x464e5449;
        puVar3[1] = 0x18;
        puVar3[4] = param_2;
        puVar3[5] = piVar1;
        local_8 = FUN_60019fce(piVar1);
      }
      *param_1 = puVar3;
    }
  }
  return local_8;
}

