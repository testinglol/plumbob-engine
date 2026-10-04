
void __thiscall FUN_00465a06(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  (**(code **)(*param_1 + 100))(param_2);
  if (param_1[2] == 0) {
    FUN_00420028(unaff_retaddr);
    iVar1 = FUN_00633a1e();
    if (iVar1 != 0) {
      iVar1 = FUN_00633a1e();
      param_1[2] = iVar1;
    }
  }
  return;
}

