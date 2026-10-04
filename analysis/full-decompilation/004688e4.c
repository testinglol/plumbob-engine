
void __thiscall FUN_004688e4(undefined2 *param_1,char param_2)

{
  float fVar1;
  char cVar2;
  
  cVar2 = FUN_00468851();
  if ((((cVar2 == '\0') && (*(char *)((int)param_1 + 0x73) != param_2)) &&
      (*(char *)((int)param_1 + 0x75) == '\0')) &&
     ((*(char *)((int)param_1 + 0x73) = param_2, *(int *)(param_1 + 0x140) == 0 &&
      (*(float *)(param_1 + 0x36) < DAT_00667638)))) {
    FUN_0040766a(0xf1,*param_1);
    fVar1 = DAT_00667638;
    if (*(char *)((int)param_1 + 0x73) == '\0') {
      fVar1 = *(float *)(param_1 + 0x36);
    }
    FUN_00467805(param_1 + 2,fVar1);
  }
  return;
}

