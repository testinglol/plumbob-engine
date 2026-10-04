
void __thiscall FUN_005e46f0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x38] != param_2) {
    param_1[0x38] = param_2;
    (**(code **)(*param_1 + 0x1b0))();
    (**(code **)(*param_1 + 0x168))();
    iVar1 = (**(code **)(*param_1 + 0x18))();
    if (iVar1 != 0) {
      piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
      (**(code **)(*piVar2 + 0x168))();
    }
  }
  return;
}

