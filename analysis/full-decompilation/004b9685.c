
void __thiscall FUN_004b9685(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint *local_8;
  
  iVar2 = param_2;
  FUN_004b91b0();
  *(undefined4 *)(param_1 + 4) = 0;
  iVar4 = *(int *)(param_2 + 4);
  *(int *)(param_1 + 0xc) = iVar4;
  pvVar3 = operator_new(iVar4 << 2);
  *(void **)(param_1 + 8) = pvVar3;
  if (pvVar3 != (void *)0x0) {
    *(undefined1 *)(param_1 + 0x10) = 0;
    piVar1 = (int *)(param_2 + 4);
    param_2 = 0;
    if (*piVar1 != 0) {
      puVar6 = (undefined1 *)(iVar2 + 0x11);
      local_8 = (uint *)(param_1 + 0x20);
      do {
        iVar4 = param_2 * 4;
        *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = puVar6[-1];
        *(undefined1 *)(*(int *)(param_1 + 8) + 1 + iVar4) = *puVar6;
        *(undefined1 *)(*(int *)(param_1 + 8) + 2 + iVar4) = puVar6[1];
        puVar5 = (undefined1 *)(iVar4 + *(int *)(param_1 + 8));
        param_2 = param_2 + 1;
        *local_8 = (uint)CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]);
        puVar6 = puVar6 + 3;
        local_8 = local_8 + 1;
      } while (param_2 < *(uint *)(iVar2 + 4));
    }
    FUN_004b9471();
  }
  return;
}

