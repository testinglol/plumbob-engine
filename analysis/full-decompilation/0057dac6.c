
void FUN_0057dac6(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x18) = extraout_ECX;
  iVar4 = extraout_ECX[0x71];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  if (((char)iVar4 != '\0') && (extraout_ECX[0x72] == 0)) {
    if (extraout_ECX[0x2a] != 0) {
      iVar4 = extraout_ECX[0x26];
      iVar1 = *extraout_ECX;
      *(int *)(unaff_EBP + -0x1c) = iVar4;
      iVar3 = (**(code **)(iVar1 + 0x88))(iVar4);
      iVar4 = extraout_ECX[0x27];
      iVar1 = extraout_ECX[0x25];
      if (iVar4 == 0) {
        extraout_ECX[0x2a] = 0;
      }
      if (iVar3 < iVar1 != 0 < iVar4) {
        iVar4 = -iVar4;
      }
      iVar3 = iVar3 + iVar4;
      if (((0 < iVar4) && (iVar1 < iVar3)) || ((iVar4 < 0 && (iVar3 < iVar1)))) {
        extraout_ECX[0x2a] = 0;
        iVar3 = iVar1;
      }
      (**(code **)(*extraout_ECX + 0x84))(*(undefined4 *)(unaff_EBP + -0x1c),iVar3,0);
    }
    iVar4 = DAT_006f6a78;
    if ((*(char *)((int)extraout_ECX + 0x1cf) == '\0') || (extraout_ECX[0x2a] != 0)) {
      iVar1 = *(int *)(DAT_006f6a78 + 0x58);
      *(int *)(unaff_EBP + -0x1c) = iVar1;
      if (iVar1 < 0) {
        (**(code **)(iVar4 + 200))(extraout_ECX,s_Timer_wrapped_around_while_at_br_006cf5dc);
      }
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      uVar2 = extraout_ECX[0x66];
      if ((uVar2 != 0) && (uVar2 <= *(uint *)(unaff_EBP + -0x1c))) {
        if ((int)uVar2 < 0) {
          (**(code **)(DAT_006f6a78 + 200))
                    (extraout_ECX,s_Instruction_time_wrapped_around_w_006cf5a8);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_0057e3dc();
        FUN_0057dbfe();
        return;
      }
      if ((extraout_ECX[0x65] != 0) && ((uint)extraout_ECX[0x65] <= *(uint *)(unaff_EBP + -0x1c))) {
        if ((int *)extraout_ECX[0x74] != (int *)0x0) {
          (**(code **)(*(int *)extraout_ECX[0x74] + 0x98))(0);
        }
        extraout_ECX[0x65] = 0;
      }
    }
    else {
      (**(code **)(*extraout_ECX + 0x38))();
      *(undefined1 *)((int)extraout_ECX + 0x1cf) = 0;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

