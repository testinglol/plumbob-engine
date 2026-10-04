
void __fastcall FUN_004ee157(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(param_1 + 4);
  if (*(uint *)(param_1 + 0x10) < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) {
    puVar2 = *(undefined4 **)(*piVar1 + *(uint *)(param_1 + 0x10) * 4);
    uVar3 = puVar2[7];
    FUN_005b8e25(uVar3);
    FUN_005b9796(uVar3);
    uVar3 = puVar2[0x4b];
    FUN_005b8e25(uVar3);
    FUN_005b9796(uVar3);
    uVar3 = puVar2[0x8f];
    FUN_005b8e25(uVar3);
    FUN_005b9796(uVar3);
    *puVar2 = 0;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_004ed447();
      FUN_006321f0(puVar2);
    }
    FUN_0052ea87(*piVar1 + *(int *)(param_1 + 0x10) * 4,*piVar1 + 4 + *(int *)(param_1 + 0x10) * 4);
    if ((uint)(*(int *)(param_1 + 8) - *piVar1 >> 2) <= *(uint *)(param_1 + 0x10)) {
      *(int *)(param_1 + 0x10) = (*(int *)(param_1 + 8) - *piVar1 >> 2) + -1;
    }
  }
  return;
}

