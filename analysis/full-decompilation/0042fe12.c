
void __fastcall FUN_0042fe12(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)*param_1;
  puVar3 = (undefined4 *)*puVar1;
  while (puVar3 != puVar1) {
    puVar2 = (undefined4 *)*puVar3;
    FUN_00430980();
    FUN_0040189d(puVar3,0x1c);
    puVar3 = puVar2;
  }
  *puVar1 = puVar1;
  puVar1[1] = puVar1;
  return;
}

