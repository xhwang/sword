#include "assign.h"
#include <cstring>

CMyString::CMyString(char* pData) {
  m_pData = new char[strlen(pData)+1];
  strcpy(m_pData, pData);
}

// TODO: implicitly-declared only shallow copy
CMyString::CMyString(const CMyString& str) {
  // TODO: private member?
  // Access control works on per-class basis 
  m_pData = new char[strlen(str.m_pData)+1];
  strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void) {
  delete []m_pData;
  m_pData = nullptr;
}

CMyString& CMyString::operator=(const CMyString& str) {

  if (this != &str) {
    CMyString strTemp(str);
    char *pTemp = strTemp.m_pData;
    strTemp.m_pData = m_pData;
    m_pData = pTemp;
  }

  // TODO: *this dereference
  return *this;
}

char* CMyString::getData() {
  return m_pData;
}
