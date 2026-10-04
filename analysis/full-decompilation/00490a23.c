
void FUN_00490a23(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  char cVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  iVar1 = DAT_006e54dc;
  *(undefined4 *)(unaff_EBP + -0x2c) = extraout_ECX;
  iVar3 = *(int *)(iVar1 + 0x10);
  *(int *)(unaff_EBP + -0x30) = iVar3;
  if (0 < iVar3) {
    do {
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      do {
        *(undefined1 *)(unaff_EBP + -0x1e) = 1;
        *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0x28);
        *(undefined1 *)(unaff_EBP + -0x1f) = *(undefined1 *)(unaff_EBP + -0x24);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar3 = FUN_004905f5(unaff_EBP + -0x20);
        if (*(char *)(*(int *)(*(int *)(*(int *)(unaff_EBP + 8) + 0xc) +
                              *(char *)(unaff_EBP + -0x20) * 4) + 1 +
                     *(char *)(unaff_EBP + -0x1f) * 4) != *(char *)(iVar3 + 1)) {
          *(char *)(unaff_EBP + -0x1c) = *(char *)(unaff_EBP + -0x20);
          *(undefined1 *)(unaff_EBP + -0x1b) = *(undefined1 *)(unaff_EBP + -0x1f);
          *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(unaff_EBP + -0x1e);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          puVar4 = (undefined1 *)FUN_00489c8e(unaff_EBP + -0x1c);
          *puVar4 = 0x80;
          FUN_00461b74(&DAT_006e481c);
          cVar2 = *(char *)(unaff_EBP + -0x1c) + *(char *)(unaff_EBP + -0x10);
          cVar5 = *(char *)(unaff_EBP + -0x1b) + *(char *)(unaff_EBP + -0xf);
          *(undefined1 *)(unaff_EBP + -0xe) = 0;
          *(char *)(unaff_EBP + -0x1c) = cVar2;
          *(char *)(unaff_EBP + -0x1b) = cVar5;
          if ('\0' < cVar2) {
            iVar3 = *(int *)(iVar1 + 0x10) + -1;
            if (((cVar2 < iVar3) && ('\0' < cVar5)) && (cVar5 < iVar3)) {
              *(undefined1 *)
               (*(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0xc) + cVar2 * 4) + (int)cVar5) = 0x80;
            }
          }
          FUN_00461b74(&DAT_006e4822);
          cVar2 = *(char *)(unaff_EBP + -0x1c) + *(char *)(unaff_EBP + -0x14);
          cVar5 = *(char *)(unaff_EBP + -0x1b) + *(char *)(unaff_EBP + -0x13);
          *(undefined1 *)(unaff_EBP + -0x12) = 0;
          *(char *)(unaff_EBP + -0x1c) = cVar2;
          *(char *)(unaff_EBP + -0x1b) = cVar5;
          if ('\0' < cVar2) {
            iVar3 = *(int *)(iVar1 + 0x10) + -1;
            if (((cVar2 < iVar3) && ('\0' < cVar5)) && (cVar5 < iVar3)) {
              *(undefined1 *)
               (*(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0xc) + cVar2 * 4) + (int)cVar5) = 0x80;
            }
          }
          FUN_00461b74(&DAT_006e481f);
          cVar2 = *(char *)(unaff_EBP + -0x1c) + *(char *)(unaff_EBP + -0x18);
          cVar5 = *(char *)(unaff_EBP + -0x1b) + *(char *)(unaff_EBP + -0x17);
          *(undefined1 *)(unaff_EBP + -0x16) = 0;
          *(char *)(unaff_EBP + -0x1c) = cVar2;
          *(char *)(unaff_EBP + -0x1b) = cVar5;
          if ('\0' < cVar2) {
            iVar3 = *(int *)(iVar1 + 0x10) + -1;
            if (((cVar2 < iVar3) && ('\0' < cVar5)) && (cVar5 < iVar3)) {
              *(undefined1 *)
               (*(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0xc) + cVar2 * 4) + (int)cVar5) = 0x80;
            }
          }
          FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
          FUN_004916e1(unaff_EBP + -0x20);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
      } while (*(int *)(unaff_EBP + -0x24) < *(int *)(unaff_EBP + -0x30));
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
    } while (*(int *)(unaff_EBP + -0x28) < *(int *)(unaff_EBP + -0x30));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

