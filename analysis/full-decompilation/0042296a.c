
void __thiscall FUN_0042296a(int *param_1,short param_2)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  ushort uVar5;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = param_1[0x3d];
  local_c = param_1[0x3e];
  local_8 = param_1[0x44];
  (**(code **)(*param_1 + 0x50))(1);
  uVar5 = (short)param_1[0x1e] * param_2 & 7;
  if (uVar5 != 0) {
    piVar4 = (int *)param_1[100];
    cVar3 = (char)uVar5;
    piVar1 = param_1;
    if (piVar4 != (int *)0x0) goto LAB_004229b8;
    while (piVar4 = piVar1, piVar4 != (int *)0x0) {
LAB_004229b8:
      *(ushort *)(piVar4 + 0x13) = (byte)((char)piVar4[0x13] + cVar3) & 7;
      FUN_004341a6(0);
      FUN_00434f7b();
      piVar1 = (int *)piVar4[99];
    }
    (**(code **)(*param_1 + 0x88))();
    cVar2 = (**(code **)(*param_1 + 0x54))(&local_10,local_8,0,0);
    if ((cVar2 == '\0') && (cVar2 = FUN_00422665(&local_10), cVar2 == '\0')) {
      piVar4 = (int *)param_1[100];
      piVar1 = param_1;
      if (piVar4 != (int *)0x0) goto LAB_00422a21;
      while (piVar4 = piVar1, piVar4 != (int *)0x0) {
LAB_00422a21:
        *(ushort *)(piVar4 + 0x13) = (byte)((char)piVar4[0x13] - cVar3) & 7;
        piVar1 = (int *)piVar4[99];
      }
      (**(code **)(*param_1 + 0x88))();
    }
    cVar3 = (**(code **)(*param_1 + 0x54))(&local_10,local_8,0,0);
    if (cVar3 != '\0') {
      (**(code **)(*param_1 + 0x58))(&local_10,local_8,0,0,1);
    }
  }
  return;
}

