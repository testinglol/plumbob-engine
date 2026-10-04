
void __thiscall FUN_0042ec52(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((param_2 + 1 != puVar1) &&
     (iVar2 = (int)puVar1 - (int)(param_2 + 1) >> 2, puVar3 = param_2, param_2 = (undefined4 *)iVar2
     , 0 < iVar2)) {
    do {
      param_2 = (undefined4 *)((int)param_2 + -1);
      *puVar3 = puVar3[1];
      puVar3 = puVar3 + 1;
    } while (param_2 != (undefined4 *)0x0);
  }
  *(undefined4 **)(param_1 + 4) = puVar1 + -1;
  return;
}

