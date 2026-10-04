
undefined4 __thiscall FUN_0057bfad(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  
  fVar1 = (float)param_2;
  if (((fVar1 == *(float *)(param_1 + 0xc)) && ((float)param_3 == *(float *)(param_1 + 0x10))) &&
     ((float)param_4 == *(float *)(param_1 + 0x14))) {
    return 1;
  }
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 0x10) = (float)param_3;
  *(float *)(param_1 + 0x14) = (float)param_4;
  (**(code **)(**(int **)(param_1 + 0x20) + 0x24))
            (fVar1,(float)param_3,(float)param_4,0,0x3f800000,0);
  return 1;
}

