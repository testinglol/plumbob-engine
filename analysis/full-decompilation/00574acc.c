
void __fastcall FUN_00574acc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  
  piVar4 = (int *)0x0;
  if (DAT_006f63d4 != 0) {
    piVar4 = (int *)FUN_00573466(DAT_006f63d4);
  }
  iVar2 = DAT_006f63d4;
  if (((*(char *)(param_1 + 0xd) == '\0') && (*(char *)(param_1 + 0xc) != '\0')) &&
     (*(int *)(param_1 + 0xe8) == 0)) {
    DAT_006f63d4 = FUN_00574a7e();
    if ((DAT_006f63d4 != iVar2) && (piVar4 != (int *)0x0)) {
      (**(code **)(*piVar4 + 0x34))();
    }
    if (DAT_006f63d4 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_00573466(DAT_006f63d4);
    }
    if (piVar4 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar4 + 0x70))();
      if (cVar3 == '\0') {
        uVar1 = *(undefined4 *)(&DAT_0067156c + *(int *)(param_1 + 0xf0) * 4);
        (**(code **)(*piVar4 + 0x30))(0,0,0);
        (**(code **)(*piVar4 + 0x40))(0);
        (**(code **)(*piVar4 + 0x84))(0x28,uVar1,0);
        (**(code **)(*piVar4 + 0x84))(0x29,0x13,0);
        (**(code **)(*piVar4 + 0x84))(0x2a,5000,0);
        (**(code **)(*piVar4 + 0x84))(0x2d,1,0);
        (**(code **)(*piVar4 + 0x5c))();
      }
    }
  }
  else if (piVar4 != (int *)0x0) {
    cVar3 = (**(code **)(*piVar4 + 0x70))();
    if (cVar3 != '\0') {
      (**(code **)(*piVar4 + 0x34))();
    }
  }
  return;
}

