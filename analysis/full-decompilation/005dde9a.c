
void __fastcall FUN_005dde9a(int *param_1)

{
  int *piVar1;
  
  (**(code **)(*param_1 + 0x168))();
  piVar1 = *(int **)param_1[0xe];
  if (piVar1 != (int *)param_1[0xe]) {
    do {
      (**(code **)(*(int *)piVar1[2] + 0x16c))();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)param_1[0xe]);
  }
  return;
}

