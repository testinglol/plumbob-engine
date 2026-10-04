
void __thiscall FUN_005f0352(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *local_c;
  int *local_8;
  
  piVar1 = (int *)param_1[0x1c];
  local_c = param_1;
  local_8 = param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,&local_8);
    (**(code **)(*local_8 + 0xc))(local_8,&local_c);
    (**(code **)(*local_c + 0x1c))(local_c,0);
    (**(code **)(*local_8 + 8))(local_8);
    (**(code **)(*local_c + 8))(local_c);
    *(undefined1 *)(param_1 + 0x1d) = 0;
    param_1[0x1c] = 0;
  }
  if (DAT_006feca4 == 1) {
    piVar1 = (int *)(**(code **)*DAT_006fe8bc)();
    (**(code **)(*piVar1 + 0x34))(0);
  }
  else {
    piVar1 = (int *)(**(code **)*DAT_006fe8bc)();
    (**(code **)(*piVar1 + 0x30))(param_2);
    FUN_005dddc1();
  }
  return;
}

