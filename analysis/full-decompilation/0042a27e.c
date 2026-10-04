
void __thiscall FUN_0042a27e(int param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  FUN_00445999(param_2);
  FUN_006323d0(&DAT_006c08dc);
  FUN_006323d0(s_Neighbors__006c2860);
  for (puVar2 = *(undefined4 **)(param_1 + 0x148); puVar2 != *(undefined4 **)(param_1 + 0x14c);
      puVar2 = puVar2 + 1) {
    puVar1 = (undefined2 *)*puVar2;
    if (puVar1 != (undefined2 *)0x0) {
      puVar5 = &DAT_006c08dc;
      uVar4 = *(undefined4 *)(*(int *)(puVar1 + 4) + 0x18);
      puVar3 = &DAT_006c285c;
      FUN_006330c7(CONCAT22((short)((uint)puVar1 >> 0x10),*puVar1));
      FUN_006323d0(puVar3);
      FUN_006323d0(uVar4);
      FUN_006323d0(puVar5);
    }
  }
  return;
}

