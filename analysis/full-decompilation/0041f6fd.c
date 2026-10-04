
bool __thiscall FUN_0041f6fd(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  
  puVar1 = (undefined4 *)FUN_0041f748(param_2);
  bVar2 = puVar1 != *(undefined4 **)(param_1 + 8);
  if (bVar2) {
    *param_3 = *puVar1;
    param_3[1] = puVar1[1];
    param_3[2] = puVar1[2];
  }
  return bVar2;
}

