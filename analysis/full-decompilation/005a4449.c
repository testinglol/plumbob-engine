
undefined4 FUN_005a4449(void)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar5;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  iVar1 = *(int *)(extraout_ECX + 0x22c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar1 <= *(int *)(extraout_ECX + 0x228)) {
    uVar2 = *(undefined4 *)(unaff_EBP + 8);
    do {
      cVar3 = FUN_005a45c5();
      if (cVar3 == '\0') {
        FUN_005d5156(unaff_EBP + -0x18,s_End_of_file_in_sentance_006d1e78);
        FUN_00575805(unaff_EBP + -0x18);
        break;
      }
      if (0 < *(int *)(extraout_ECX + 0x234)) {
        cVar3 = FUN_005a4684();
        if (cVar3 == '\0') {
          pcVar5 = s_Sentance_without_directive_token_006d1eb0;
LAB_005a453a:
          FUN_005d5156(unaff_EBP + -0x18,pcVar5);
          FUN_00575805(unaff_EBP + -0x18);
        }
        else {
          uVar4 = FUN_005d4916(*(int *)(extraout_ECX + 0x238) + *(int *)(extraout_ECX + 0x224),
                               *(undefined4 *)(extraout_ECX + 0x23c));
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005d499c(uVar4);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          cVar3 = FUN_00460748(unaff_EBP + -0x24,PTR_s_BITMAP_006d1e54);
          if ((cVar3 == '\0') &&
             (cVar3 = FUN_00460748(unaff_EBP + -0x24,PTR_s_RLEBMP_006d1e5c), cVar3 == '\0')) {
            cVar3 = FUN_00460748(unaff_EBP + -0x24,PTR_s_INCLUDE_006d1e58);
            if (cVar3 == '\0') {
              pcVar5 = s_Unknown_Directive_in_Sentance_006d1e90;
              goto LAB_005a453a;
            }
            FUN_005a4c21(uVar2);
          }
          else {
            uVar4 = FUN_00460748(unaff_EBP + -0x24,PTR_s_RLEBMP_006d1e5c);
            FUN_005a47ae(uVar2,uVar4);
          }
        }
      }
    } while (*(int *)(extraout_ECX + 0x22c) <= *(int *)(extraout_ECX + 0x228));
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

