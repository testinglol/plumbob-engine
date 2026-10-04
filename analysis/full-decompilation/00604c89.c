
byte __fastcall FUN_00604c89(int *param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = (**(code **)(*param_1 + 8))(0x10);
  bVar2 = cVar1 != '\0';
  cVar1 = (**(code **)(*param_1 + 8))(0x11);
  if (cVar1 != '\0') {
    bVar2 = bVar2 | 2;
  }
  cVar1 = (**(code **)(*param_1 + 8))(0x12);
  if (cVar1 != '\0') {
    bVar2 = bVar2 | 4;
  }
  return bVar2;
}

