
void __thiscall FUN_005ddfdc(int *param_1,undefined4 param_2)

{
  undefined4 unaff_ESI;
  int *piVar1;
  
  (**(code **)(*param_1 + 0x90))(0x4000,param_2);
  piVar1 = *(int **)param_1[0xe];
  if (piVar1 != (int *)param_1[0xe]) {
    do {
      FUN_005ddfdc(unaff_ESI);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)param_1[0xe]);
  }
  return;
}

