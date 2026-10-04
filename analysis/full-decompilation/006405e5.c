
void FUN_006405e5(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_006dd350 == param_1) {
    PTR_LOOP_006dd350 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_006db330) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00703ff8,0,param_1);
    return;
  }
  DAT_006db340 = 0xffffffff;
  return;
}

