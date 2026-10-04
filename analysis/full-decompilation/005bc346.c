
int __thiscall FUN_005bc346(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(-(uint)(param_2 != 0) & param_2 + 4U);
  if (puVar1 != (undefined4 *)(param_1 + 4)) {
    FUN_00431779(*puVar1,puVar1[1]);
  }
  return param_1;
}

