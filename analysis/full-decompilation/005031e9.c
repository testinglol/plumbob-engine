
void __thiscall FUN_005031e9(int param_1,int param_2)

{
  int *piVar1;
  
  *(int *)(param_1 + 0xd4) = -param_2;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x7c))
              (*(int *)(param_1 + 0xd4),*(int *)(param_1 + 0xd4) >> 0x1f,param_1 + 0xf4);
  }
  *(undefined1 *)(param_1 + 0xe4) = 1;
  return;
}

