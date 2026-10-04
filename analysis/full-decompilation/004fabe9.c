
undefined1 FUN_004fabe9(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  size_t sVar4;
  undefined4 uVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  FUN_0041308b();
  iVar6 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),0);
  if (((iVar2 == 0) && (iVar2 = FUN_00412fc7(unaff_EBP + -0x10), iVar2 == 0)) &&
     (iVar2 = FUN_004131a0(0), iVar2 == 0)) {
    pvVar3 = operator_new(*(uint *)(unaff_EBP + -0x10));
    *(void **)(unaff_EBP + -0x14) = pvVar3;
    if (pvVar3 != (void *)0x0) {
      iVar2 = FUN_00413178(pvVar3,unaff_EBP + -0x10);
      if (iVar2 == 0) {
        FUN_0046f824(unaff_EBP + -0x43c,0,0x400);
        *(undefined ***)(unaff_EBP + -0x448) = &PTR_FUN_0066773c;
        *(undefined4 *)(unaff_EBP + 8) = 0;
        do {
          *(undefined2 *)(unaff_EBP + -0x440) = 0;
          **(undefined1 **)(unaff_EBP + -0x444) = 0;
          if (iVar6 < *(int *)(unaff_EBP + -0x10)) {
            do {
              if ((*(char *)(iVar6 + (int)pvVar3) != ' ') &&
                 (*(char *)(iVar6 + (int)pvVar3) != '\t')) break;
              iVar6 = iVar6 + 1;
            } while (iVar6 < *(int *)(unaff_EBP + -0x10));
            if (*(int *)(unaff_EBP + -0x10) <= iVar6) goto LAB_004faced;
            if (*(char *)(iVar6 + (int)pvVar3) != '#') {
              do {
                cVar1 = *(char *)(iVar6 + (int)pvVar3);
                *(char *)(unaff_EBP + -0x30) = cVar1;
                if ((cVar1 == '\r') || (cVar1 == '\n')) break;
                FUN_0046fa24(*(undefined4 *)(unaff_EBP + -0x30));
                iVar6 = iVar6 + 1;
              } while (iVar6 < *(int *)(unaff_EBP + -0x10));
              goto LAB_004faced;
            }
          }
          else {
LAB_004faced:
            if ((*(short *)(unaff_EBP + -0x440) != 0) &&
               (cVar1 = FUN_005e64a0(*(undefined4 *)(unaff_EBP + -0x444)), cVar1 == '\0')) {
              FUN_005d4956(s_Error_on_line_006cbf48);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_004015e4(*(char *)(unaff_EBP + 8) + '\x01');
              sVar4 = _strlen(s___Continue__006cbf58);
              FUN_00412d8a(s___Continue__006cbf58,s___Continue__006cbf58 + sVar4);
              uVar5 = FUN_005d4956(s_Cht_file_006cbf3c);
              iVar2 = *(int *)(DAT_006f2a08 + 0x48);
              *(undefined1 *)(unaff_EBP + -4) = 2;
              iVar2 = (**(code **)(iVar2 + 0x2c))(unaff_EBP + -0x20,uVar5,3,0);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_005b8770();
              if (iVar2 != 4) {
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_005b8770();
                pvVar3 = *(void **)(unaff_EBP + -0x14);
                break;
              }
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_005b8770();
              pvVar3 = *(void **)(unaff_EBP + -0x14);
            }
          }
          iVar2 = *(int *)(unaff_EBP + -0x10);
          if (iVar6 < iVar2) {
            do {
              if ((*(char *)(iVar6 + (int)pvVar3) == '\r') ||
                 (*(char *)(iVar6 + (int)pvVar3) == '\n')) break;
              iVar6 = iVar6 + 1;
            } while (iVar6 < iVar2);
            for (; (iVar6 < iVar2 &&
                   ((*(char *)(iVar6 + (int)pvVar3) == '\r' ||
                    (*(char *)(iVar6 + (int)pvVar3) == '\n')))); iVar6 = iVar6 + 1) {
            }
          }
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        } while (iVar6 < iVar2);
        *(undefined1 *)(unaff_EBP + 0xb) = 1;
      }
      else {
        *(undefined1 *)(unaff_EBP + 0xb) = 0;
      }
      FUN_006321f0(pvVar3);
      goto LAB_004fadde;
    }
  }
  *(undefined1 *)(unaff_EBP + 0xb) = 0;
LAB_004fadde:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004130c0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + 0xb);
}

