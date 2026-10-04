
void __thiscall FUN_0050a33d(int *param_1,char param_2)

{
  int *piVar1;
  
  if (param_2 != (char)param_1[0x35]) {
    *(char *)(param_1 + 0x35) = param_2;
    if (param_2 == '\0') {
      (**(code **)(*(int *)param_1[0x3e] + 0x98))();
      piVar1 = (int *)FUN_0050aacf();
      (**(code **)(*piVar1 + 0x94))();
    }
    else {
      (**(code **)(*(int *)param_1[0x3e] + 0x94))();
      (**(code **)(*(int *)param_1[0x3e] + 0x44))();
      piVar1 = (int *)FUN_0050aacf();
      (**(code **)(*piVar1 + 0x98))();
    }
    (**(code **)(*param_1 + 0x168))();
  }
  return;
}

