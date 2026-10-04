
void __thiscall FUN_00401466(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_004015a1(*(undefined4 *)(param_1 + 0xc));
  if (iVar1 == 0) {
    FUN_0040149e();
  }
  iVar1 = FUN_004015a1(*(undefined4 *)(param_1 + 0xc));
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_004015a1(*(undefined4 *)(param_1 + 0xc));
    *puVar2 = param_2;
  }
  return;
}

