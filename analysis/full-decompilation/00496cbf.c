
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496cbf(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  int unaff_EBP;
  float10 fVar6;
  
  FUN_00634c24();
  pcVar2 = *(char **)(unaff_EBP + 0xc);
  cVar5 = *pcVar2;
  cVar4 = pcVar2[1];
  cVar1 = pcVar2[2];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(char *)(unaff_EBP + 0xc) = cVar5;
  *(char *)(unaff_EBP + 0xd) = cVar4;
  *(char *)(unaff_EBP + 0xe) = cVar1;
  iVar3 = *(int *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar3 == 0) {
    if (*(int *)(unaff_EBP + 0x14) == 0) goto LAB_00496e70;
    if (*(int *)(unaff_EBP + 0x14) < 1) {
      FUN_00461b74();
      cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
      cVar4 = *(char *)(unaff_EBP + 0x15);
    }
    else {
      FUN_00461b74();
      cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
      cVar4 = *(char *)(unaff_EBP + 0x15);
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = DAT_00673438;
    fVar6 = (float10)FUN_00636dc4((double)*(int *)(unaff_EBP + 0x14) /
                                  (double)*(int *)(unaff_EBP + 0x10));
    if (fVar6 <= (float10)*(float *)(unaff_EBP + -0x10) * (float10)_DAT_00668224) {
      if (fVar6 <= (float10)*(float *)(unaff_EBP + -0x10) * (float10)_DAT_00668220) {
        if (fVar6 <= (float10)*(float *)(unaff_EBP + -0x10) * (float10)_DAT_0066821c) {
          if (fVar6 <= (float10)*(float *)(unaff_EBP + -0x10) * (float10)_DAT_00668218) {
            if (*(int *)(unaff_EBP + 0x14) < 1) {
              FUN_00461b74();
              cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
              cVar4 = *(char *)(unaff_EBP + 0x15);
            }
            else {
              FUN_00461b74();
              cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
              cVar4 = *(char *)(unaff_EBP + 0x15);
            }
          }
          else if (iVar3 < 1) {
            FUN_00461b74();
            cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
            cVar4 = *(char *)(unaff_EBP + 0x15);
          }
          else {
            FUN_00461b74();
            cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
            cVar4 = *(char *)(unaff_EBP + 0x15);
          }
        }
        else if (iVar3 < 1) {
          FUN_00461b74();
          cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
          cVar4 = *(char *)(unaff_EBP + 0x15);
        }
        else {
          FUN_00461b74();
          cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
          cVar4 = *(char *)(unaff_EBP + 0x15);
        }
      }
      else if (iVar3 < 0) {
        FUN_00461b74();
        cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
        cVar4 = *(char *)(unaff_EBP + 0x15);
      }
      else {
        FUN_00461b74();
        cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
        cVar4 = *(char *)(unaff_EBP + 0x15);
      }
    }
    else {
      FUN_00461b74();
      cVar5 = cVar5 + *(char *)(unaff_EBP + 0x14);
      cVar4 = *(char *)(unaff_EBP + 0x15);
    }
  }
  *(char *)(unaff_EBP + 0xd) = *(char *)(unaff_EBP + 0xd) + cVar4;
LAB_00496e70:
  pcVar2 = *(char **)(unaff_EBP + 8);
  pcVar2[1] = *(char *)(unaff_EBP + 0xd);
  pcVar2[2] = *(char *)(unaff_EBP + 0xe);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *pcVar2 = cVar5;
  return;
}

