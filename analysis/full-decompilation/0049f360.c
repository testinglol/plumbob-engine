
undefined4 __fastcall FUN_0049f360(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = ((float)*param_1 / (float)param_1[2]) * DAT_00673438;
  FUN_00636d14((double)(fVar1 + fVar1));
  uVar2 = __ftol();
  *param_1 = (*param_1 + 1) % param_1[2];
  return uVar2;
}

