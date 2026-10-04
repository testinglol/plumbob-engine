
int __fastcall FUN_0046894e(short *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int local_4;
  
  local_4 = 0;
  iVar1 = *(int *)(*DAT_006e486c + 0x14);
  piVar4 = *(int **)(iVar1 + 0x84);
  if (piVar4 != *(int **)(iVar1 + 0x88)) {
    do {
      iVar2 = *piVar4;
      cVar3 = FUN_00435294();
      if ((cVar3 == '\0') && (*(short *)(iVar2 + 0xafc) == *param_1)) {
        local_4 = local_4 + 1;
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(iVar1 + 0x88));
  }
  return local_4;
}

