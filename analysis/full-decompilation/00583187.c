
int * FUN_00583187(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_28 [2];
  int local_20;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_8;
  
  local_8 = 0;
  piVar1 = (int *)FUN_005a9320(0xc);
  if ((*(int *)(*param_1 + 0x10) == param_2) && (*(int *)(*param_1 + 0x14) == param_3)) {
    puVar2 = (undefined4 *)FUN_005a9320(0x2890);
    *piVar1 = (int)puVar2;
    puVar7 = (undefined4 *)*param_1;
    for (iVar4 = 0xa24; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar2 = puVar2 + 1;
    }
    iVar4 = param_1[2];
    piVar1[2] = iVar4;
    puVar2 = (undefined4 *)FUN_005a9320(*(int *)(*piVar1 + 0x14) * iVar4);
    piVar1[1] = (int)puVar2;
    uVar5 = *(int *)(*piVar1 + 0x14) * piVar1[2];
    puVar7 = (undefined4 *)param_1[1];
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  else {
    local_28[0] = param_2;
    local_20 = param_3;
    local_18 = 0;
    local_10 = 0;
    FUN_0060c8f0(&DAT_006d0420);
    FUN_0060c810(&local_8,1,param_1,4,local_28);
    iVar4 = FUN_0060c850(local_8,0);
    *piVar1 = iVar4;
    iVar3 = (*(int *)(iVar4 + 0x18) * *(int *)(iVar4 + 0x10)) / 8;
    piVar1[2] = iVar3;
    iVar4 = FUN_005a9320(*(int *)(iVar4 + 0x14) * iVar3);
    piVar1[1] = iVar4;
    FUN_0060c880(local_8,*piVar1,iVar4,piVar1[2]);
    FUN_0060c8c0(local_8);
  }
  return piVar1;
}

