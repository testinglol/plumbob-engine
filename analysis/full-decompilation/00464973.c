
void __thiscall FUN_00464973(int *param_1,short *param_2,int param_3)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = param_1[3];
  if (*(char *)((int)param_1 + 0x13) == '\0') {
    if (iVar3 == 2) {
      param_1[2] = param_1[2] + param_3 * 2;
    }
    else {
      if (iVar3 == 0) {
        psVar1 = (short *)(param_1[2] + *param_1);
        psVar2 = param_2;
      }
      else {
        psVar2 = (short *)(param_1[2] + *param_1);
        psVar1 = param_2;
      }
      if (0 < param_3) {
        do {
          if ((short)param_1[4] == 0) {
            *psVar2 = *psVar1;
          }
          else {
            *(undefined1 *)psVar2 = *(undefined1 *)((int)psVar1 + 1);
            *(char *)((int)psVar2 + 1) = (char)*psVar1;
          }
          param_1[2] = param_1[2] + 2;
          psVar1 = psVar1 + 1;
          psVar2 = psVar2 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
  }
  else if ((iVar3 == 1) || (iVar3 == 2)) {
    iVar3 = param_3;
    psVar1 = param_2;
    if (0 < param_3) {
      do {
        param_2 = (short *)(int)*psVar1;
        FUN_00464696(&param_2,&DAT_006e52c8);
        iVar3 = iVar3 + -1;
        psVar1 = psVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar3 = param_3;
    psVar1 = param_2;
    if (0 < param_3) {
      do {
        FUN_00464696(&param_2,&DAT_006e52c8);
        *psVar1 = (short)param_2;
        iVar3 = iVar3 + -1;
        psVar1 = psVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  return;
}

