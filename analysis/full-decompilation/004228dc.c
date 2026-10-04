
void __thiscall FUN_004228dc(int param_1,int param_2)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(int *)(param_1 + 400) = param_2;
  if (param_2 != 0) {
    do {
      piVar1 = (int *)(param_2 + 0x18c);
      param_2 = *piVar1;
    } while (param_2 != 0);
    *piVar1 = param_1;
  }
  return;
}

