
void __fastcall FUN_005dd31f(int *param_1)

{
  int *piVar1;
  
  (**(code **)(*param_1 + 0x18c))();
  piVar1 = *(int **)param_1[0xe];
  if (piVar1 != (int *)param_1[0xe]) {
    do {
      (**(code **)(*(int *)piVar1[2] + 400))();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)param_1[0xe]);
  }
  return;
}

