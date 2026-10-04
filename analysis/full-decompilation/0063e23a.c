
void FUN_0063e23a(LPVOID param_1)

{
  if (DAT_006db310 != 0xffffffff) {
    if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_006db310), param_1 != (LPVOID)0x0)) {
      if (*(int *)((int)param_1 + 0x24) != 0) {
        FUN_00634ecc(*(int *)((int)param_1 + 0x24));
      }
      if (*(int *)((int)param_1 + 0x28) != 0) {
        FUN_00634ecc(*(int *)((int)param_1 + 0x28));
      }
      if (*(int *)((int)param_1 + 0x30) != 0) {
        FUN_00634ecc(*(int *)((int)param_1 + 0x30));
      }
      if (*(int *)((int)param_1 + 0x38) != 0) {
        FUN_00634ecc(*(int *)((int)param_1 + 0x38));
      }
      if (*(int *)((int)param_1 + 0x40) != 0) {
        FUN_00634ecc(*(int *)((int)param_1 + 0x40));
      }
      if (*(int *)((int)param_1 + 0x44) != 0) {
        FUN_00634ecc(*(int *)((int)param_1 + 0x44));
      }
      if (*(undefined **)((int)param_1 + 0x50) != &DAT_006ddc98) {
        FUN_00634ecc(*(undefined **)((int)param_1 + 0x50));
      }
      FUN_00634ecc(param_1);
    }
    TlsSetValue(DAT_006db310,(LPVOID)0x0);
    return;
  }
  return;
}

