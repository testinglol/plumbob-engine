
void __fastcall FUN_005f4008(int *param_1)

{
  char cVar1;
  
  if ((int *)param_1[0x44] != (int *)0x0) {
    if ((param_1[0x4c] != 0) && (param_1[0x4c] < param_1[0x3d] - param_1[0x3c] >> 2)) {
      cVar1 = (**(code **)(*(int *)param_1[0x44] + 0x8c))(1);
      if (cVar1 == '\0') {
        (**(code **)(*(int *)param_1[0x44] + 0x94))();
        param_1[0x48] =
             param_1[0x48] + (*(int *)(param_1[0x44] + 0x7c) - *(int *)(param_1[0x44] + 0x84));
        if (param_1[0x4d] != 1) {
          param_1[0x42] = (param_1[0x48] - param_1[0x46]) + -5;
          param_1[0x43] = 0x7fff;
        }
        FUN_005f3a06(0);
      }
      (**(code **)(*(int *)param_1[0x44] + 0x1ac))(0);
      (**(code **)(*(int *)param_1[0x44] + 0x1b0))
                ((param_1[0x3d] - param_1[0x3c] >> 2) - param_1[0x4c]);
      (**(code **)(*(int *)param_1[0x44] + 0x1a8))(param_1[0x4b]);
      return;
    }
    param_1[0x4b] = 0;
    param_1[0x40] = param_1[0x41];
    (**(code **)(*param_1 + 0x168))();
    cVar1 = (**(code **)(*(int *)param_1[0x44] + 0x8c))(1);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)param_1[0x44] + 0x98))();
      param_1[0x48] =
           param_1[0x48] + (*(int *)(param_1[0x44] + 0x84) - *(int *)(param_1[0x44] + 0x7c));
      if (param_1[0x4d] != 1) {
        param_1[0x42] = (param_1[0x48] - param_1[0x46]) + -5;
        param_1[0x43] = 0x7fff;
      }
      FUN_005f3a06(0);
    }
  }
  return;
}

